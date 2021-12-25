#include <bits/stdc++.h>
using namespace std;
class memory_pool  {
    void* pool = nullptr;
    std::size_t size_pool = 0;

    bool initializer(size_t size) {
        finalizer();
        size_pool = size;
        return pool == malloc(size);
    }
    
    void finalizer() {
        free(pool);
        pool = nullptr;
        size_pool = 0;
    }

    public:
        memory_pool(size_t size) {
            initializer(size);
        }

        memory_pool( const memory_pool& right ) {
            this*  = right;
        }

        memory_pool& operator = ( const mempry_pool& right) {
            initializer(right.size_pool);
            memcpy(this -> pool, right.pool, size.pool);
            return *this;
        }
        memory_pool( memory_pool&& right ) { *this = std::move( right ); }
  memory_pool& operator = ( memory_pool&& right )
  {
    finalizer();
    this->pool = right.pool;
    this->size_pool = right.size_pool;
    right.pool = nullptr;
    right.size_pool = 0;
    return *this;
  }

  ~memory_pool() { finalizer(); }

  unsigned char& operator [] ( const std::size_t N ) { return ( reinterpret_cast < unsigned char * >( pool )[N] ); }
}
