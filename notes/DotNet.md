# DotNet

## get MSSQL running on MAC

```bash
## get the SQL server image
docker pull mcr.microsoft.com/mssql/server:2019-CU3-ubuntu-18.04

## docker run this image
docker run -e "ACCEPT_EULA=Y" -e "SA_PASSWORD=reallyStrongPwd#123" -p 1433:1433 --name localsql -d mcr.microsoft.com/mssql/server:2019-CU3-ubuntu-18.04

## sql-cli
npm install -g sql-cli
mssql -u sa -p reallyStrongPwd#123

## sql commands
SELECT Name from sys.Databases
SELECT @@SERVERNAME, SERVERPROPERTY('ComputerNamePhysicalNetBIOS'), SERVERPROPERTY('MachineName'), SERVERPROPERTY('ServerName')
```

## dotnet ef commands

```bash
dotnet tool install --global dotnet-ef
dotnet add package Microsoft.EntityFrameworkCore.Design
dotnet ef migrations add Initial -o Data/Migrations
dotnet ef database update
```

## dotnet upgrade packages

```babsh
dotnet tool install --global dotnet-outdated
dotnet outdated --version-lock major --upgrade
```

## dotnet test & coverage

```bash
dotnet tool install -g dotnet-reportgenerator-globaltool
dotnet test /p:CollectCoverage=true /p:CoverletOutputFormat=opencover /p:Threshold=100 /p:ThresholdType=line
reportgenerator -reports:coverage.opencover.xml -targetdir:~/gitws/code-coverage/report
```
