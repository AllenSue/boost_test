#ifndef BOOSTTESTER_HPP
#define BOOSTTESTER_HPP

#include "boost/asio.hpp"
#include "boost/asio/steady_timer.hpp"
#include "boost/thread.hpp"

class BoostTester {
 public:
  BoostTester() : timer(io) {
    timer.expires_from_now(std::chrono::seconds(1));
    timer.async_wait(boost::bind(&BoostTester::onTimer, this));
  }

  ~BoostTester() {
    io.stop();
    thd.interrupt();
    thd.join();
  }

  void onTimer() {
    std::printf("on timer...\n");
    timer.expires_at(timer.expires_at() + std::chrono::seconds(1));
    timer.async_wait(boost::bind(&BoostTester::onTimer, this));
  }

  void start() {
    thd = boost::thread(boost::bind(&BoostTester::entry, this));
  }

  void entry() {
    io.run();
  }

 private:
  boost::asio::io_service io;
  boost::asio::steady_timer timer;
  boost::thread thd;

};

#endif // BOOSTTESTER_HPP
