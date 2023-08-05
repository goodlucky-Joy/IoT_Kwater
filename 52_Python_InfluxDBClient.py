from influxdb_client.client.write_api import SYNCHRONOUS
from datetime import datetime
from influxdb_client import InfluxDBClient
from influxdb_client.client.write_api import SYNCHRONOUS

# InfluxDB 연결 정보
url = "http://localhost:8086"
token = "DB_TOKEN"
org = "DB_ORG"
bucket = "DB_BUCKET"



# InfluxDB 클라이언트 생성
client = InfluxDBClient(url=url, token=token, org=org)

# write_api 인스턴스 생성
write_api = client.write_api(write_options=SYNCHRONOUS)

# 데이터 생성 및 쓰기
point = Point("home").tag("room", "kitchen").field("temp", 22.2).field("hum", 36.4).field("co", 17).time(datetime(2022, 1, 1, 8, 0, 0))

# 데이터 포인트 쓰기
write_api.write(bucket=bucket, org=org, record=point)
print("데이터 입력 성공!")
