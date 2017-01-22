from bs4 import BeautifulSoup
import pandas
import time
from selenium import webdriver


url = 'http://w3.sbs.co.kr/tv/tvsectionMainImg.do?pgmCtg=T&pgmSct=DR&pgmSort=week&div=pc_drama'
driver = webdriver.Firefox()
driver.get(url)

source_code = driver.page_source
soup = BeautifulSoup(source_code, 'lxml')

title_list = list()
broad_list = list()
type_list = list()


for link in soup.find_all('strong', {'class': 'smdpb_tit'}):
    link = link.contents
    title_list.append(link[0])
    broad_list.append("SBS")
    type_list.append("drama")
    

    
    
driver.find_element_by_link_text("종영 프로그램").click()    
source_code = driver.page_source
soup = BeautifulSoup(source_code, 'lxml')


for link in soup.find_all('strong', {'class': 'smdpb_tit'}):
    link = link.contents
    title_list.append(link[0])
    broad_list.append("SBS")
    type_list.append("drama")
    
    
    
    
    
drama_title = pandas.DataFrame({'Broadcaster' : broad_list,'title' : title_list,'type' : type_list})
f=open("C:/Users/jaehyun/Crawling/drama_list/SBS.csv","w")
f.write(pandas.DataFrame.to_csv(drama_title))
f.close()