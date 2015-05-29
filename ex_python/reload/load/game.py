import config
import subprocess
import a

print config.data

subprocess.call(["cp", "../config.py", "config.py"])
reload(config)

a.def_a()
