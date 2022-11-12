starting = Process.clock_gettime(Process::CLOCK_MONOTONIC)
# time consuming operation
threads = []
threads << Thread.new {
  cart = [
    { "id" => 1, "product" => "iPhone", "price" => 499.0 },
    { "id" => 2, "product" => "Kindle", "price" => 179.0 },
    { "id" => 3, "product" => "Macbook Pro", "price" => 1199.0 }
  ]
  cartPrices = cart.map { |item| item["price"] }
  cartSum = cartPrices.sum()
  cart.each do |item|
    puts item
  end
  puts cartSum
}
threads << Thread.new {
  cart = [
    { "id" => 1, "product" => "PlayStation 5", "price" => 499.0 },
    { "id" => 2, "product" => "Bike", "price" => 179.0 },
    { "id" => 3, "product" => "iPad Pro", "price" => 1099.0 }
  ]
  cartPrices = cart.map { |item| item["price"] }
  cartSum = cartPrices.sum()
  cart.each do |item|
    puts item
  end
  puts cartSum
}
threads << Thread.new {
  cart = [
    { "id" => 1, "product" => "Galaxy S20 Ultra", "price" => 599.0 },
    { "id" => 2, "product" => "Samsung pen", "price" => 179.0 },
    { "id" => 3, "product" => "Samsung OLED", "price" => 1199.0 }
  ]
  cartPrices = cart.map { |item| item["price"] }
  cartSum = cartPrices.sum()
  cart.each do |item|
    puts item
  end
  puts cartSum
}

threads.each { |thr| thr.join }

ending = Process.clock_gettime(Process::CLOCK_MONOTONIC)
elapsed = ending - starting
puts elapsed.to_s + " seconds"