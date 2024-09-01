#include "byte_stream.hh"

using namespace std;

ByteStream::ByteStream( uint64_t capacity )
  : Push_size_( 0 ), Buffer_size_( 0 ), Pop_size_( 0 ), capacity_( capacity ), is_closed_( false )
{}

bool Writer::is_closed() const
{
  // Your code here.

  return is_closed_;
}

void Writer::push( string data )
{
  // Your code here.
  if ( has_error() || is_closed_ )
    return;
  const uint64_t len = min( data.length(), available_capacity() );
  if ( len > 0 ) {
    Push_size_ += len;
    Buffer_size_ += len;
    buffer_.append( data.substr( 0, len ) );
  }
}

void Writer::close()
{
  // Your code here.
  if ( !is_closed_ ) {
    is_closed_ = true;
  }
}

uint64_t Writer::available_capacity() const
{

  return capacity_ - Buffer_size_;
}

uint64_t Writer::bytes_pushed() const
{
  // Your code here.
  return Push_size_;
}

bool Reader::is_finished() const
{
  // Your code here.
  return is_closed_ && Buffer_size_ == 0;
}

uint64_t Reader::bytes_popped() const
{
  // Your code here.
  return Pop_size_;
}

string_view Reader::peek() const
{
  // Your code here.
  return string_view( buffer_ );
}

void Reader::pop( uint64_t len )
{
  // Your code here.
  len = min( len, Buffer_size_ );
  if ( len > 0 ) {
    Buffer_size_ -= len;
    Pop_size_ += len;
    buffer_.erase( 0, len );
  }
}

uint64_t Reader::bytes_buffered() const
{
  // Your code here.
  return Buffer_size_;
}
