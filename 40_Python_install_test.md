### Python 설치 및 테스트
---
### https://www.python.org/downloads/
#### C:\Users\사용자\AppData\Local\Programs\Python\Python3XX
---
#### 설치시 환경변수 추가 안 했다면 수동으로 PATH 추가
#### 명령프롬프트>echo %PATH%
#### 명령프롬프트>setx PATH "%PATH%;C:\Users\사용자\AppData\Local\Programs\Python\Python3XX"
---
#### 파이썬 버전 확인
#### 명령프롬프트>python --version
---
#### Python 개발을 위한 모듈 설치
#### 명령프롬프트>pip3 –m pip install –upgrade pip
#### 명령프롬프트>pip3 install paho-mqtt          //MQTT
#### 명령프롬프트>pip3 install influxdb           //InfluxDB v1
#### 명령프롬프트>pip3 install influxdb-client    //InfluxDB v2
#### 명령프롬프트>pip install notebook            //jupyter notebook

---
#### 주피터 노트북 실행
#### 명령프롬프트>jupyter notebook
