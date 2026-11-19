#!/usr/bin/env bash
# Разворачивает песочницу: распаковывает broken-repo.zip рядом с собой.
# Linux и macOS - обычный терминал. Windows - Git Bash (идёт вместе с Git).
set -e

cd "$(dirname "$0")"

if [ -d broken-repo ]; then
    echo "папка broken-repo уже есть, ничего не делаю"
    exit 0
fi

[ -f broken-repo.zip ] || { echo "рядом нет broken-repo.zip"; exit 1; }

echo "распаковываю broken-repo.zip..."

# На Windows в Git Bash обычно нет unzip, зато есть python или PowerShell.
if command -v unzip >/dev/null 2>&1; then
    unzip -q broken-repo.zip
elif command -v python3 >/dev/null 2>&1; then
    python3 -m zipfile -e broken-repo.zip .
elif command -v python >/dev/null 2>&1; then
    python -m zipfile -e broken-repo.zip .
elif command -v powershell.exe >/dev/null 2>&1; then
    powershell.exe -NoProfile -Command \
        "Expand-Archive -LiteralPath 'broken-repo.zip' -DestinationPath '.' -Force"
elif command -v tar >/dev/null 2>&1 && tar -tf broken-repo.zip >/dev/null 2>&1; then
    tar -xf broken-repo.zip
else
    echo "не нашел, чем распаковать: нет ни unzip, ни python, ни PowerShell."
    echo "распакуйте broken-repo.zip вручную - получится та же папка broken-repo."
    exit 1
fi

[ -d broken-repo ] || { echo "после распаковки нет папки broken-repo"; exit 1; }

cat <<'TXT'

готово. дальше:

    cd broken-repo
    bash check.sh

check.sh соберет проект, прогонит тесты и покажет, что в репозитории не так.
TXT
