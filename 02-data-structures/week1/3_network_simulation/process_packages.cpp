#include <iostream>
#include <queue>
#include <vector>


/// Network packet processing simulation
///
/// Intro: In this problem you will implement a program to simulate the processing of network packets.
///
/// Task: You are given a series of incoming network packets, and your task is to simulate their processing. Packets
///       arrive in some order. For each packet number i, you know the time when it arrived A_i and the time it takes the
///       processor to process it P_i (both in milliseconds). There is only one processor, and it processes the incoming
///       packets in the order of their arrival. If the processor started to process some packet, it doesn’t interrupt or
///       stop until it finishes the processing of this packet, and the processing of packet i takes exactly P_i milliseconds.
///
///       The computer processing the packets has a network buffer of fixed size S. When packets arrive, they are stored in
///       the buffer before being processed. However, if the buffer is full when a packet arrives (there are S packets which
///       have arrived before this packet, and the computer hasn’t finished processing any of them), it is dropped and won’t be
///       processed at all. If several packets arrive at the same time, they are first all stored in the buffer (some of them
///       may be dropped because of that — those which are described later in the input). The computer processes the packets in
///       the order of their arrival, and it starts processing the next available packet from the buffer as soon as it finishes
///       processing the previous one. If at some point the computer is not busy, and there are no packets in the buffer, the
///       computer just waits for the next packet to arrive. Note that a packet leaves the buffer and frees the space in the
///       buffer as soon as the computer finishes processing it.
///
/// Input: The first line of the input contains the size S of the buffer and the number n of incoming network packets. Each of
///        the next n lines contains two numbers. i-th line contains the time of arrival A_i and the processing time P_i (both
///        in milliseconds) of the i-th packet. It is guaranteed that the sequence of arrival times is non-decreasing (however,
///        it can contain the exact same times of arrival in milliseconds — in this case the packet which is earlier in the
///        input is considered to have arrived earlier).
///
/// Output: For each packet output either the moment of time (in milliseconds) when the processor began processing it or −1 if
///         the packet was dropped (output the answers for the packets in the same order as the packets are given in the input).


struct Request {
  Request(int arrival_time, int process_time)
  : arrival_time(arrival_time)
  , process_time(process_time)
  {}
  
  int arrival_time;
  int process_time;
};


struct Response {
  Response(bool dropped, int start_time)
  : dropped(dropped)
  , start_time(start_time)
  {}
  
  bool dropped;
  int start_time;
};


class Buffer {
public:
  Buffer(int size)
  : size_(size)
  , finish_time_()
  {}

  Response Process(const Request& request) {
    // TASK CODE IS HERE
    Response res(false, 0);

    if (finish_time_.empty()) {
      res.start_time = request.arrival_time;
      finish_time_.push(request.arrival_time + request.process_time);
    }
    else {
      // Not empty,
      // but need to check when receive new request whether the old request completed.
      while (!finish_time_.empty()) {
        if (request.arrival_time >= finish_time_.front()) {
          finish_time_.pop();
        }
        else {
          // Buffer is full
          if (finish_time_.size() == size_) {
            res.start_time = 0;
            res.dropped    = true;
          }
          else if (finish_time_.size() < size_) {
            // Buffer is not full, current request can be stored in the buffer
            // But its start_time_ and finish_time_ depends on the last one in the buffer
            res.start_time = finish_time_.back();
            finish_time_.push(res.start_time + request.process_time);
          }

          break;
        }
      }
      // Buffer is empty
      if (finish_time_.empty()) {
        res.start_time = request.arrival_time;
        finish_time_.push(request.arrival_time + request.process_time);
      }
    }

    return res;
  }

private:
    int size_;
    std::queue <int> finish_time_;
};


std::vector <Request> ReadRequests() {
  std::vector <Request> requests;
  int count;
  std::cin >> count;

  for (int i = 0; i < count; ++i) {
    int arrival_time, process_time;
    std::cin >> arrival_time >> process_time;
    requests.push_back(Request(arrival_time, process_time));
  }

  return requests;
}


std::vector <Response> ProcessRequests(const std::vector <Request>& requests, Buffer* buffer) {
  std::vector <Response> responses;

  for (int i = 0; i < requests.size(); ++i) {
    responses.push_back(buffer->Process(requests[i]));
  }

  return responses;
}


void PrintResponses(const std::vector <Response>& responses) {
  for (int i = 0; i < responses.size(); ++i) {
    std::cout << (responses[i].dropped ? -1 : responses[i].start_time) << std::endl;
  }
}


int main() {
  int size;

  std::cin >> size;
  std::vector <Request> requests = ReadRequests();

  Buffer buffer(size);
  std::vector <Response> responses = ProcessRequests(requests, &buffer);

  PrintResponses(responses);

  return 0;
}
