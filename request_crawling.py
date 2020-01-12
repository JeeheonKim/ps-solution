mport requests
from bs4 import BeautifulSoup as bs

LOGIN_INFO = {
            'login_user_id' : '',  # boj ID
                'login_password' : ''  # boj PW
                }

with requests.Session() as s:
        # login
            req = s.post('https://www.acmicpc.net/signin', data=LOGIN_INFO)
                if req.status_code == 200: 
                            print('login success')
                                else:
                                            print('login failure')
                                                    raise Exception('???? ?? ?????.')

                                                    while True: 
                                                                try:
                                                                                # ? ?? ???? ?? ??? ??, ? ?? ?? ??? ??? exception? ?????,
                                                                                            # ?? exception? ???? ??? ???? ???? ????.
                                                                                                        files = input().split() 
                                                                                                                except:
                                                                                                                                break

                                                                                                                                    # ???? ????? ??? ???? ????.
                                                                                                                                            for file in files:
                                                                                                                                                            name = file.split('.')                      # ???? ???? ????.
                                                                                                                                                                        search_url = 'https://boj.kr/' + name[0][3:]            # ?? url? ???.
                                                                                                                                                                                    page = s.get(search_url)                    # request? ?? ??? ??.
                                                                                                                                                                                                html = page.text                        # html? ????.
                                                                                                                                                                                                            soup = bs(html, 'html.parser')                  # bs? ???? ????.

                                                                                                                                                                                                                        problem_name = soup.select('#problem_title')[0].text        # ?? ??? ???.
                                                                                                                                                                                                                                    print(name[0][3:] + ' ' + name[1] + ' ' + problem_name, end=' ')# ?? ??, ???, ?? ??? ??

                                                                                                                                                                                                                                                spoilers = soup.select('#problem_tags > ul > li')       # ???? ??? ???? ???? ????.
                                                                                                                                                                                                                                                            for spoiler in spoilers:                    # ??? ???? ??? ????.
                                                                                                                                                                                                                                                                                print(spoiler.text, end=' ')
                                                                                                                                                                                                                                                                                            print('')           
