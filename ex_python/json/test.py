import json
fp = open('test.json')
#data = fp.read()
#result = json.loads(data)
#print(result)

result = json.load(fp)
print type(result), result

