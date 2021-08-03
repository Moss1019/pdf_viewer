
from requests import request
from bs4 import BeautifulSoup


class Scraper(object):
    _pos_options = ['Noun', 'Verb', 'Adjective', 'Adverb', 'Preposition']
    _noun = 0
    _verb = 1
    _adjective = 2
    _adverb = 3
    _preposition = 4

    def __init__(self):
        self._tags = []

    def get_result(self, word):
        url = "https://en.wiktionary.org/wiki/%s" % word
        page = request("get", url).text
        soup = BeautifulSoup(page, features="html.parser")
        self._fill_tags(soup)
        pos = self._get_pos()

    def _get_meaning(self):
        return []

    def _get_pos(self):
        for e in self._tags:
            if e.name == 'h4' or e.name == 'h3':
                if e.find('span').text in Scraper._pos_options:
                    return Scraper._pos_options.index(e.find('span').text)

    def _get_german(self, pos):
        pass

    def _get_romanian(self, pos):
        pass

    def _fill_tags(self, soup):
        found_english = False
        for e in soup.find_all():
            if e.name == 'h2' and 'English' in e.text:
                found_english = True
                continue
            if found_english:
                if e.name == 'h2':
                    break
                else:
                    self._tags.append(e)


if __name__ == '__main__':
    s = Scraper()
    s.get_result('in')
