This code were writen and tested in centos linux system. For development 
used boost::Python library. For compliation used following command:

g++ command:
	g++ -Wall -Wextra -fPIC -shared -I/u/logic/depot/anaconda2/include/python2.7 -lboost_python iso.cpp -o iso.so