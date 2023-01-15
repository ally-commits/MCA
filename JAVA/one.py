from selenium import webdriver
from selenium.webdriver.chrome.service import Service
from webdriver_manager.chrome import ChromeDriverManager
from selenium.common.exceptions import TimeoutException
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.common.by import By

PATH = "/usr/local/bin/chromedriver" # Location of the webdriver file

s=Service(ChromeDriverManager().install())
driver = webdriver.Chrome(service=s)
driver.get('https://web.whatsapp.com')
# driver.implicitly_wait(20) 
timeout = 100
try:
    myElem = WebDriverWait(driver, 100).until(EC.presence_of_element_located((By.ID, 'NEW ID')))
    print("Page is ready!")
except TimeoutException:
    print("Loading took too much time!")
# driver.find_element_by_css_selector("span[title='" + input("Enter name to spam: ") + "']").click()
# driver.findElement(By.clan)
# driver.find_element("xpath","//span[@title='Sharon 🎈']").click()
inputString = input("Enter message to send: ")

while(True):
    driver.find_element("xpath","//div[@title='Type a message']").send_keys(inputString)
    driver.find_element("xpath","//*[@id='main']/footer/div[1]/div[1]/span[2]/div[1]/div[2]/div[2]/button").click()


# document.getElementById("hard_expire_time").id = "NEW ID";