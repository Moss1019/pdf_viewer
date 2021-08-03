
import requests
import bs4

page = requests.request("get", "https://en.wiktionary.org/wiki/man").text

soup = bs4.BeautifulSoup(page, features="html.parser")

found_english = False

nums = [1,2,3,4]



