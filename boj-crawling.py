import requests
from bs4 import BeautifulSoup as bs

response = requests.get('https://www.acmicpc.net/step')
html = response.text

soup = bs(html, 'html.parser')
tag = soup.td
print(tag, type(tag))
tag = soup.a
print(tag, type(tag))
