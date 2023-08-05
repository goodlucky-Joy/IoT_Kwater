### InfluxDB 설치 및 테스트 for Windows
---
### https://docs.influxdata.com/influxdb/v2.7/install/?t=Windows
#### 압축풀어서 C:\Program Files\InfluxData\influxdb 폴더에 복사 (파일탐색기)
---
#### 관리자모드 PowerShell>cd c:\users\a\downloads
#### C:\users\a\downloads> dir '.\influxdb2-2.7.0-windows-amd64.zip'
#### C:\users\a\downloads> Expand-Archive .\influxdb2-2.7.0-windows-amd64.zip -DestinationPath 'C:\Program Files\InfluxData\'
#### C:\users\a\downloads> mv 'C:\Program Files\InfluxData\influxdb2-2.7.0-windows-amd64' 'C:\Program Files\InfluxData\influxdb'
---
#### InfluxDB 실행
#### C:\users\a\downloads> cd -Path 'C:\Program Files\InfluxData\influxdb\'
#### C:\Program Files\InfluxData\influxdb\> ./influxd
#### 엑세스 허용


