from bs4 import BeautifulSoup
import pandas
import requests
import csv
import time

period = list()
viewer_rating = list()
user_like = list()
story = list()
with open("C:/Users/jaehyun/Crawling/drama_list/drama_list(KBS,MBC,SBS,tvN).csv") as csvfile:
    reader = csv.DictReader(csvfile)
    for row in reader:
        title = row['title']
        url = "https://search.naver.com/search.naver?sm=tab_hty.top&where=nexearch&oquery=w&ie=utf8&query=%s+출연자"%title
        temp = requests.get(url)
        temp.encoding = "utf-8"
        source_code = temp.text
        soup = BeautifulSoup(source_code, 'lxml')
                    
        
        
        if(soup.find('div',class_='info_bar')):
            info = soup.find('div',class_='info_bar')
            if(len(info)>6):
                print(url)
                period.append(info.contents[6])
            
            else:
                period.append(info.contents[4])
        else :
            period.append(" ")
        
        
        if(soup.find('em',class_='fred')):
            view = soup.find('em',class_='fred')
            viewer_rating.append(view.text)
        else :
            viewer_rating.append(" ")
        
        
        if(soup.find('em',class_='u_cnt _cnt')):
            like = soup.find('em',class_='u_cnt _cnt')
            user_like.append(like.text)
        else :
            user_like.append(" ")
                       
                
        if(soup.find('dd',class_='intro _multiLayerContainer')):
            story_temp = soup.find('dd',class_='intro _multiLayerContainer')
            story.append(story_temp.text)
        elif(soup.find('div',class_='ly_smry',id='layer_sy')):
            story_temp = soup.find('div',class_='ly_smry',id='layer_sy')
            story.append(story_temp.text)            
        else :
            story.append(" ")

        time.sleep(1)
        

 
drama = pandas.DataFrame({'Broadcaster' : broad_list,'title' : title_list,'type' : type_list, 'Period' : period, 'viewer_rating' : viewer_rating, 'user_like' : user_like, 'Story' : story})


f=open("C:/Users/jaehyun/Crawling/drama_list/drama.csv","w")
f.write(pandas.DataFrame.to_csv(drama))
f.close()