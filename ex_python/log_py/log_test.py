import logging
logging.basicConfig(filename='test.log', level=logging.DEBUG)
logging.info("log info...\n")
logging.warning("log warning...\n")


logger = logging.Logger("test")
try:
    a = 1/0
except Exception, e:
    logger.exception(e)
