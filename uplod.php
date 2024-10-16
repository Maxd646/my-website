<?php
// Check if the form is submitted
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    // Get form data
    $title = htmlspecialchars($_POST['title']);
    $content = htmlspecialchars($_POST['content']);

    // You can save data to a text file or a database. 
    // Here is an example of saving to a text file:

    $data = "Title: $title\nContent: $content\n\n";
    file_put_contents('uploads.txt', $data, FILE_APPEND);

    // Redirect back to the main page with a success message
    header("Location: index.html?success=1");
    exit();
}
?>
