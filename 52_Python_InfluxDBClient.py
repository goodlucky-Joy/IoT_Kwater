from influxdb_client import InfluxDBClient, Point
from influxdb_client.client.write_api import SYNCHRONOUS
from datetime import datetime

# InfluxDB 연결 정보
url = "http://localhost:8086"
token = "DB_TOKEN"
org = "DB_ORG"
bucket = "DB_BUCKET"

# InfluxDB 클라이언트 생성
client = InfluxDBClient(url=url, token=token)

# 데이터 포인트 생성
point = Point("home").tag("room", "kitchen").field("temp", 25.5).field("hum", 60).field("co",3i).time(datetime.utcnow())

# 데이터 쓰기
write_api = client.write_api(write_options=SYNCHRONOUS)
write_api.write(bucket=bucket, org=org, record=point)

# 데이터 읽기
query = f'from(bucket: "{bucket}") |> range(start: -1h)'
tables = client.query_api().query(query, org=org)
for table in tables:
    for row in table.records:
        print(f'Time: {row["_time"]}, Location: {row["location"]}, Temperature: {row["_value"]}')
