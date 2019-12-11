# GIT

## migrate repo

```
git clone --mirror [old-repo-url]
cd [the-repo]
git remote add [new-remote-name] [new-repo-url]
git push --mirror [new-remote-name]
