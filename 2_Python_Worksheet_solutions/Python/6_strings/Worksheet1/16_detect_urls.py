import re

s = "Check this link: https://openai.com and http://github.com"
urls = re.findall(r'https?://\S+', s)
print(urls)