<?php 
   
   $conn=new mysqli('localhost', 'root', '', 'lista de calificaciones');
   if($conn->connect_error){
       echo $error -> $conn->connect_error;
   }

?>