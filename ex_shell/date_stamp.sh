stamp=`date '+%s'`
echo $stamp
curl -b "org_loc=%2Fmpay%2Fget_balance_m; session_id=hy_gameid; session_type=wc_actoken" http://msdktest.qq.com/mpay/get_balance_m\?openid\=oiqIwt_xLaH5R_4db9WKQ7lUnI-s\&pf\=wechat_wx-73213123-android-73213123-wx-wxf77437c08cb06196-oiqIwt_xLaH5R_4db9WKQ7lUnI-s\&sig\=SnIMwgRWjh9975K4eaqUc6MNzRs%3D\&pfkey\=1832d3805abacf7f3c5c7389ac0667c2\&appid\=1104297231\&pay_token\=\&openkey\=OezXcEiiBSKSxW0eoylIeJIptOH5pbMgimZXNYDPrYd9-qjHFtPBP0YXpa2liXM4VA2MSaYnrlOcbCXDT_sxgHSgjRj8_KweJtP7sxPzGfTSrja5XJDXH3Pm2YfASiDVKsCErK9ZX9fn6Wx8w42sXg\&format\=json\&ts\=$stamp\&zoneid\=1
