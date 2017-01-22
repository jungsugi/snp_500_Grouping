from bs4 import BeautifulSoup
import pandas
import requests

title_list = list()
broad_list = list()
type_list = list()

for page in range(1,5):
    url = "http://ch.interest.me/tvn/Program?page=%s&onair=E&code=CAT008&order="%page
    temp = requests.get(url)
    temp.encoding = "utf-8"
    source_code = temp.text
    soup = BeautifulSoup(source_code, 'lxml')
    
    for link in soup.find_all('span',{'class':'title'}):
        link = link.text
        title_list.append(link)
        broad_list.append("tvN")
        type_list.append("drama")


 
drama_title = pandas.DataFrame({'Broadcaster' : broad_list,'title' : title_list,'type' : type_list})
f=open("C:/Users/jaehyun/Crawling/drama_list/tvN.csv","w")
f.write(pandas.DataFrame.to_csv(drama_title))
f.close()