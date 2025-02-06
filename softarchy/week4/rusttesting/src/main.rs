use std::thread;
// to install from your terminal-

// curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh

// then do   source $HOME/.cargo/env
// then do rustc --version       (to verify)




// cargo new rusttesting 

// cargo run (if you're not using a shared folder so you can actually code on windows lol)

// or if you're mentally sane and use a shared folder use    cargo build --target-dir /tmp/rust_build

// then to run /tmp/rust_build/debug/rusttesting

// if you also cba you can just manually copy over the made directory from your shared folder to home or something


fn main() {
    let name = "Alice"; // Immutable variable
    let mut age = 30;   // Mutable variable
    // this sort of explicit definition allows you to not worry about variables that should not change...end up changing lol
    println!("Name: {}, Age: {}", name, age);


//     ⣿⣿⣿⣿⡿⠟⠛⠛⠛⠛⠉⠉⠙⠛⠛⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠿⠟⠂⠀
// ⣿⣿⣯⣤⣤⣶⣶⣶⣶⣿⣿⣿⣿⣿⣿⣶⣾⣿⣿⣿⣿⣿⣿⣿⣏⠀⣀⣀⡀⠀
// ⣿⣿⣿⣿⣿⣿⣿⡿⠿⠟⠛⠛⠿⠟⠉⠉⠉⢻⣿⣿⣿⡿⠟⠛⢉⣼⣿⣿⣿⠀
// ⣿⣿⣿⣿⣭⣤⣴⣶⣿⣿⠃⠀⠀⢀⣀⣤⣶⣿⣿⣿⣿⡇⠀⠀⣩⣤⣤⠀⠀⠀
// ⣿⣿⣿⣿⣿⣿⣟⠛⠛⠛⠛⢋⣩⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣟⠛⠛⠃⠀⠀⠀
// ⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣦⣤⣤⣤⣄⠀
// ⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡄
// ⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⢿⣿⡿⢿⣿⣿⣿⣿⣿⣿⠃
// ⠿⠿⠿⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣭⣁⣀⡀⠀⠀⠀⠀⠀⢠⣾⣿⣿⠏⠀
// ⠀⠀⠀⠀⠀⠀⠉⣻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⣶⣤⣈⡻⠋⠁⠀⠀
// ⣰⣶⣶⣶⣶⣶⣶⣿⣿⣿⣿⣿⣿⣿⡿⠿⠿⠿⠛⠛⠛⠛⠛⠛⠛⠩⠀⠀⠀⠀
// ⣿⣿⣿⣿⣿⣿⠉⠉⠉⣿⣿⡶⠶⠶⢶⠿⠿⠛⠛⠛⠛⠛⠛⣻⣿⠃⠀⠀⠀⠀
// ⠛⠛⣿⣿⣿⣿⣷⡀⠀⠈⠛⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣼⠋⠀⠀⠀⠀⠀⠀
// ⢠⣾⣿⣿⣿⣿⣿⠿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡴⠋⠀⠀⠀⠀⠀⠀⠀
// ⠄⠙⠛⠿⣿⣿⣇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⠞⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀

    //whats lovely is it will not even compile if you dont reuse mutable variables.. very nice
    age = 45;
    println!("new age:{}",age);

    //example loop 
    for i in 1..5 { //very clear 
        println!("Iteration: {}", i);
    }

    //shifting ownership example
    let s = String::from("Hello");  
    takes_ownership(s);
    // println!("{}", s); // This would cause an error because `s` has moved.

    //borrowing example 
    let new_s = String::from("Rust");
    print_length(&new_s);  // Pass a reference, the usage of & facilitates this :)
    println!("{}", new_s);  // Still valid

    //example of concurrency, I cant even begin to explain how clean this is :o
    let handle = thread::spawn(|| {
        for i in 1..5 {
            println!("Thread: {}", i);
        }
    });

    handle.join().unwrap();  // Ensures the thread finishes execution

}

fn takes_ownership(some_string: String) {
    println!("{}", some_string);
}

fn print_length(s: &String) {
    println!("Length: {}", s.len());
}