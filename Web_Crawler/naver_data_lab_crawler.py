from selenium import webdriver
from bs4 import BeautifulSoup
import pandas

url = 'http://datalab.naver.com/'
driver = webdriver.Firefox()
driver.get(url)

source_code = driver.page_source
soup = BeautifulSoup(source_code, 'lxml')

keyword_list = list()
contents_list = list()
content_list_list=list()
for keyword in soup.find_all('strong',class_='rank_title'):
    keyword_list.append(keyword.text)

num = 0
for contents in soup.find_all('span',class_='title'):
    if(num == 10):
        num=0;
        contents_list.append(content_list_list[0] +"|"+content_list_list[1]+"|"+content_list_list[2] +"|"+content_list_list[3]+"|"+content_list_list[4]+"|"+content_list_list[5]+"|"+content_list_list[6]+"|"+content_list_list[7]+"|"+content_list_list[8]+"|"+content_list_list[9]) #구분자 "|"
        content_list_list = list()
    
    num = num+1
    content_list_list.append(contents.text)
    
    
    
naver_data_lab = pandas.DataFrame({'Keyword' : keyword_list,'top10' : contents_list})
f=open("C:/Users/jaehyun/Crawling/naver_datalab.csv","w")
f.write(pandas.DataFrame.to_csv(naver_data_lab))
f.close()