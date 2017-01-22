from bs4 import BeautifulSoup
from selenium import webdriver
import pandas
import time


kkma = Kkma()

driver = webdriver.Firefox()
driver.get("http://tv.imbc.com/endprograms.aspx?genre=1")
title_list = list()
broad_list = list()
type_list = list()

for page in range(1,29): #29까지
    count = 0
    time.sleep(0.2)
    if(page%10 !=1):
        print(page)
        driver.find_element_by_link_text(page).click();
    time.sleep(0.5)
    source_code = driver.page_source

    soup = BeautifulSoup(source_code, 'lxml')
    
    
    for title in soup.find_all('strong', {'class': 'tit'}):
        count = count+1
        if(count>3):
            print(title.string)
            title = title.string;
            title_list.append(title)
            broad_list.append("MBC")
            type_list.append("drama")
        
    if(page%10==0):
        driver.find_element_by_css_selector("#paginate.paginate a.pg-next").click()

drama_title = pandas.DataFrame({'Broadcaster' : broad_list,'title' : title_list,'type' : type_list})
f.open("C:/Users/jaehyun/Crawling/drama_list/drama_list","w")
f.write(pandas.DataFrame.to_csv(drama_title))