<?php
session_start();

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $username = $_POST['username'];
    $password = $_POST['password'];

    // Read user details from file
    $users = file("users.txt", FILE_IGNORE_NEW_LINES);
    foreach ($users as $user) {
        list($storedUser, $storedPass) = explode(":", $user);
        if ($storedUser == $username && password_verify($password, $storedPass)) {
            $_SESSION['logged_in'] = true;
            $_SESSION['username'] = $username;
            header("Location: index.html");
            exit();
        }
    }
    // If login fails
    echo "Invalid credentials. Please try again.";
}
?>
