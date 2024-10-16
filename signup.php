<?php
session_start();

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $username = $_POST['username'];
    $password = password_hash($_POST['password'], PASSWORD_DEFAULT);

    // Save user details in a file or database (Here we use a file for simplicity)
    $userData = $username . ":" . $password . "\n";
    file_put_contents("users.txt", $userData, FILE_APPEND);

    // Redirect to login page after signup
    header("Location: index.html");
    exit();
}
?>
