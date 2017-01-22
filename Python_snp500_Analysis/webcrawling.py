#! /usr/bin/python
#-*- coding: utf-8 -*-

from bs4 import BeautifulSoup
import pandas
import requests

def Spider():
    url = 'https://en.wikipedia.org/wiki/List_of_S%26P_500_companies'
    temp = requests.get(url)
    source_code = temp.text
    soup = BeautifulSoup(source_code, 'lxml')
    ticker_symbol = list()
    continue_flag = 1

    #find_all()은 list를 반환
    links = soup.find_all('table', {'class': 'wikitable'})  #첫 문자열 리스트가 'wikitable'인 첫번째 테이블-> list안에 저장[<>,<>,<>]
    #print(links)
    links = links[0].find_all("tr") # 위키첫번째테이블: links[0]
    for link in links:   #links 는 [] link는 <>
        if (continue_flag == 1):
            continue_flag = 0
            continue
        source = link.find_all('td') #source는 list의 형태 [<>,<>,<>]
        ticker_symbol.append(source[0].text)
    return ticker_symbol


    def get_website(ticker_symbol):
        url2  = None
        for data in ticker_symbol:
            url2 = 'https://finance.yahoo.com/quote/' + str(data) + '/history?p='+ str(data) + '/'
            print(url2)

