import influxdb_client
from influxdb_client.client.write_api import SYNCHRONOUS
from datetime import datetime

# InfluxDB 연결 정보
url = "http://localhost:8086"
token = "DB_TOKEN"
org = "DB_ORG"
bucket = "DB_BUCKET"

# InfluxDB 클라이언트 생성
client = InfluxDBClient(url=url, token=token, org=org)

# write_api 인스턴스 생성
write_api = client.write_api(write_options=SYNCHRONOUS)

# 데이터 포인트 생성
point = Point("home").tag("room", "kitchen").field("temp", 25.5).field("hum", 60).field("co",3).time(datetime.utcnow())

# 데이터 쓰기
write_api.write(bucket=bucket, org=org, record=point)
