use std::thread;
use std::time::{Duration, Instant};

#[derive(Debug)]
struct Items {
  id:  u64,
	product: String,
	price: f64 
}
trait NewItems {
  fn new(id: u64, product: String, price: f64) -> Self;
}
impl NewItems for Items {
  fn new(id: u64, product: String, price: f64) -> Self {
    Items { id, product, price }
  }
}

fn main() {
  let start = Instant::now();

  thread::spawn(|| {
    let _cart:[Items; 3] = [
      Items::new(1, String::from("iPhone"), 499.0),
      Items::new(2, String::from("Kindle"), 179.0),
      Items::new(3, String::from("Macbook"), 1199.0)
    ];
    println!("Cart -> {:?}", _cart);
    let cart_prices = _cart.iter().map(|x| x.price ).collect::<Vec<f64>>();
    let cart_sum: f64 = cart_prices.iter().sum();
    println!("Sum -> {:?}", cart_sum);
  });

  thread::spawn(|| {
    let _cart:[Items; 3] = [
      Items::new(1, String::from("PlayStation 5"), 499.0),
      Items::new(2, String::from("Bike"), 179.0),
      Items::new(3, String::from("iPad Pro"), 1099.0)
    ];
    println!("Cart -> {:?}", _cart);
    let cart_prices = _cart.iter().map(|x| x.price ).collect::<Vec<f64>>();
    let cart_sum: f64 = cart_prices.iter().sum();
    println!("Sum -> {:?}", cart_sum);
  });

  thread::spawn(|| {
    let _cart:[Items; 3] = [
      Items::new(1, String::from("Galaxy S20"), 599.0),
      Items::new(2, String::from("Samsung pen"), 179.0),
      Items::new(3, String::from("Samsung OLED"), 1199.0)
    ];
    println!("Cart -> {:?}", _cart);
    let cart_prices = _cart.iter().map(|x| x.price ).collect::<Vec<f64>>();
    let cart_sum: f64 = cart_prices.iter().sum();
    println!("Sum -> {:?}", cart_sum);
  });

  let duration = start.elapsed();
  thread::sleep(Duration::from_millis(1));
  println!("Time elapsed in expensive_function() is: {:?}", duration);

}
