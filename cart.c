#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <pthread.h>

struct item {
  int id;
  char product[100];
  float price;
};

pthread_t threads[3];

float * Map(struct item *arr, size_t len, float (*fn)(struct item)) {
  float* arr_res = malloc(sizeof(float) * len);
  for(size_t i = 0; i < len; ++i) {
    arr_res[i] = fn(arr[i]);
  }
  return arr_res;
};

float getPrice(struct item i) {
  return i.price;
}

float Sum(float *arr, size_t len) {
  float sum = 0;
  for (size_t i = 0; i < len; ++i) {
    sum += arr[i];
  }
  return sum;
}

void *cartOne(void *arg) {
  struct item cart[3] = {
    {1, "iPhone", 499.0},
    {2, "Kindle", 179.0},
    {3, "Macbook Pro", 1199.0}
  };
  float* cartPrices;
  float cartSum;
  size_t len;
    
  len = sizeof(cart) / sizeof(cart[0]);
  cartPrices = Map(cart, len, getPrice);
  cartSum = Sum(cartPrices, len);

  printf("Cart: \n");
  for(int i=0; i<len; i++)
  printf("{ %d %s %f }\n", cart[i].id, cart[i].product, cart[i].price);
  printf("\nSum -> %f\n", cartSum);
}

void *cartTwo(void *arg) {
  struct item cart[3] = {
    {1, "PlayStation 5", 499.0},
    {2, "Bike", 179.0},
    {3, "iPad Pro", 1099.0}
  };
  float* cartPrices;
  float cartSum;
  size_t len;
    
  len = sizeof(cart) / sizeof(cart[0]);
  cartPrices = Map(cart, len, getPrice);
  cartSum = Sum(cartPrices, len);

  printf("Cart: \n");
  for(int i=0; i<len; i++)
  printf("{ %d %s %f }\n", cart[i].id, cart[i].product, cart[i].price);
  printf("\nSum -> %f\n", cartSum);
}

void *cartThree(void *arg) {
  struct item cart[3] = {
    {1, "Galaxy S20", 599.0},
    {2, "Samsung pen", 179.0},
    {3, "Samsung OLED", 1199.0}
  };
  float* cartPrices;
  float cartSum;
  size_t len;
    
  len = sizeof(cart) / sizeof(cart[0]);
  cartPrices = Map(cart, len, getPrice);
  cartSum = Sum(cartPrices, len);

  printf("Cart: \n");
  for(int i=0; i<len; i++)
  printf("{ %d %s %f }\n", cart[i].id, cart[i].product, cart[i].price);
  printf("\nSum -> %f\n", cartSum);
}

int main() {
  struct timeval t1, t2;
  double elapsedTime;
  // start timer
  gettimeofday(&t1, NULL);

  int i, a = 12;

  pthread_create(&(threads[0]), NULL, cartOne, &a);
  pthread_create(&(threads[1]), NULL, cartTwo, &a);
  pthread_create(&(threads[2]), NULL, cartThree, &a);

  for(i=0; i<3; i++) pthread_join(threads[i], NULL);

  // stop timer
  gettimeofday(&t2, NULL);
  elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;   // us to ms
  printf("%f ms.\n", elapsedTime);

  return 0;
}