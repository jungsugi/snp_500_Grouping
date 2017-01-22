from bs4 import BeautifulSoup
import pandas
import requests

url = 'http://www.kbs.co.kr/end_program/drama/dramaend08v1.html'

temp = requests.get(url)
temp.encoding = "euc-kr"
source_code = temp.text
soup = BeautifulSoup(source_code, 'lxml')

title_list = list()
broad_list = list()
type_list = list()


for link in soup.find_all('a', {'class': 'gray'}):
    link = link.text
    title_list.append(link)
    broad_list.append("KBS")
    type_list.append("drama")
    

   


 
drama_title = pandas.DataFrame({'Broadcaster' : broad_list,'title' : title_list,'type' : type_list})
f=open("C:/Users/jaehyun/Crawling/drama_list/KBS.csv","w")
f.write(pandas.DataFrame.to_csv(drama_title))
f.close()