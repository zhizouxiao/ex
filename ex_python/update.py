import subprocess
import sys
import json

result = subprocess.check_call(["git", "tag"])

result = subprocess.check_call(["sh", "upload.sh"])
if result != 0:
    print("upload.sh exec error!")
    sys.exit(0)

# change config file
with open('index.json') as data_file:
    data = json.load(data_file)
    print(data)

print("upload finish!")
