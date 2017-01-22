#! /usr/bin/python
#-*- coding: utf-8 -*-
import sys
import urllib2
import pytz
import pandas as pd
from bs4 import BeautifulSoup
from datetime import datetime
from pandas.io.data import DataReader
from Cluster import AffinityPropagation, print_cluster_ReturnAver
from webcrawling import Spider
import csv

SITE = "http://en.wikipedia.org/wiki/List_of_S%26P_500_companies"
START = datetime(2016, 1, 1, 0, 0, 0, 0, pytz.utc)
END = datetime.today().utcnow()


def scrape_list(site):
    hdr = {'User-Agent': 'Mozilla/5.0'}
    req = urllib2.Request(site, headers=hdr)
    page = urllib2.urlopen(req)
    soup = BeautifulSoup(page)

    table = soup.find('table', {'class': 'wikitable sortable'})
    sector_tickers = dict()
    for row in table.findAll('tr'):
        col = row.findAll('td')
        if len(col) > 0:
            sector = str(col[3].string.strip()).lower().replace(' ', '_')
            ticker = str(col[0].string.strip())
            if sector not in sector_tickers:
                sector_tickers[sector] = list()
            sector_tickers[sector].append(ticker)
    return sector_tickers


def download_ohlc(sector_tickers, start, end):
    sector_ohlc = {}
    for sector, tickers in sector_tickers.iteritems():
        print 'Downloading data from Yahoo for %s sector' % sector
        data = DataReader(tickers, 'yahoo', start, end)
        for item in ['Open', 'High', 'Low']:
            data[item] = data[item] * data['Adj Close'] / data['Close']
        data.rename(items={'Open': 'open', 'High': 'high', 'Low': 'low',
                           'Adj Close': 'close', 'Volume': 'volume'},
                    inplace=True)
        data.drop(['Close'], inplace=True)
        sector_ohlc[sector] = data
    print 'Finished downloading data'
    return sector_ohlc


def store_HDF5(sector_ohlc, path):
    with pd.get_store(path) as store:
        for sector, ohlc in sector_ohlc.iteritems():
            store[sector] = ohlc


def get_snp500():
    sector_tickers = scrape_list(SITE)
    sector_ohlc = download_ohlc(sector_tickers, START, END)
    store = store_HDF5(sector_ohlc, 'snp500.h5')
    #store.to_csv('Total_Table.csv')

def get_snp500_smalldata():
    stocks = Spider()  #stock list 전부 crawling으로 받아오기
    ls_key = 'Adj Close'
    start = datetime(2016, 9, 1)
    end = datetime(2017, 1, 1)

    f = DataReader(stocks, 'yahoo', start, end)
    cleanData = f.ix[ls_key]  #Adj list만 저장.
    dataFrame = pd.DataFrame(cleanData)
    dataFrame.to_csv('table.csv')

if __name__ == '__main__':
    #get_snp500()  #s&p500 -> 전체 데이터 h5파일형태로 다운로드하기 >> h5dump -o '저장할csv파일명' -y -w 400 'h5파일명' 으로 변환
    get_snp500_smalldata()

    #table로 저장후에 실행
    dataFrame = pd.read_table('table.csv', sep=',')
    del dataFrame['Date'] #날자 column 버리기

    returns = dataFrame.pct_change()  # 주식의 변화율 계산.
    returns_corr = returns.corr()  # return의 corr 계산.
    CLUSTER = AffinityPropagation(returns_corr)
    print_cluster_ReturnAver(CLUSTER, returns)

