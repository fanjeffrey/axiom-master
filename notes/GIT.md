# GIT

## migrate repo

```bash
git clone --mirror [old-repo-url]
cd [the-repo]
git remote add [new-remote-name] [new-repo-url]
git push --mirror [new-remote-name]
```

## proxy settings

```bash
git config --global http.https://host:port.proxy http://200.200.200.200:8080
git config --global http.https://host:port.sslverify false
git config --global http.proxy http://200.200.200.200:8080
git config --global http.sslverify false
git config --global --unset http.proxy
```
