### 1. InfluxDB 설치 및 테스트 for Windows
---
### https://docs.influxdata.com/influxdb/v2.7/install/?t=Windows
#### 설치파일 다운로드 후 압축풀어서 C:\Program Files\InfluxData\influxdb 폴더에 복사 (파일탐색기)
---
#### 또는 관리자모드 PowerShell>cd c:\users\a\downloads
#### C:\users\a\downloads> dir '.\influxdb2-2.7.0-windows-amd64.zip'
#### C:\users\a\downloads> Expand-Archive .\influxdb2-2.7.0-windows-amd64.zip -DestinationPath 'C:\Program Files\InfluxData\'
#### C:\users\a\downloads> mv 'C:\Program Files\InfluxData\influxdb2-2.7.0-windows-amd64' 'C:\Program Files\InfluxData\influxdb'
---
#### InfluxDB 실행
#### C:\users\a\downloads> cd -Path 'C:\Program Files\InfluxData\influxdb\'
#### C:\Program Files\InfluxData\influxdb\> ./influxd
#### 엑세스 허용
#### http://localhost:8086/
#### Username, Password, Organization Name, Bucket Name 입력 후 API token 복사해 두기
---
### 2. Influx CLI 설치하기 for Windows
### https://docs.influxdata.com/influxdb/v2.7/tools/influx-cli/?t=Windows
#### 설치파일 다운로드 후 압축풀어서 C:\Program Files\InfluxData\influx 폴더에 복사 (파일탐색기)
---
#### 관리자모드 PowerShell> C:\Program Files\InfluxData\influx> ./influx config create --config-name default --host-url http://localhost:8086 --org MYORG --token MYTOKEN
