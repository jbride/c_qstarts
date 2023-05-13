#include <iostream>
#include <boost/system/config.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/asio.hpp>
#include <boost/lexical_cast.hpp>

/*
 * reference
 *  boost.org/doc/libs/master/doc/html/boost_asio.html
 * 
 * overview
 *  Boost.Asio is a cross-platform C++ library for network and low-level I/O programming that provides developers with a consistent asynchronous model using a modern C++ approach.
*/

int main(int argc, char *argv[]) {
    boost::asio::io_service io_service;
    auto socket = boost::shared_ptr<boost::asio::ip::tcp::socket>(new boost::asio::ip::tcp::socket(io_service));
    std::cout << "ok" << std::endl;
}
