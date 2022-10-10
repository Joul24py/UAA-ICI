<!--<?php
require('config.php');
if(isset($_SESSION["Nombre"]))
{
    header ("Location: http://http://localhost/joul24py.github.io/Principal.php");
}

if(isset($_POST["submit"]))
{
    $Nombre=$_POST["Nombre"];
    $Correo=$_POST["Correo"];
    $Contrasena =md5($_POST["Contraseña"]);
    $Ccontrasena=md5($_POST["Ccontraseña"]);
    
    
    if(Contrasena==Ccontrasena){
        $sql = "SELECT * FROM usuarios WHERE Correo = '$Correo'";
        $result = mysqli_query($conn, $sql);
        
        if(!$result -> num_rows = 0){
            $sql = "INSERT INTO usuarios (Nombre, Correo, Contraseña) VALUE ('$Nombre', '$Correo','$Contrasena')";
            $result = mysqli_query($conn,$sql);
            
            if($result){
                echo "<script>alert(Usuario registrado con éxito)</script>";
                $Nombre = "";
                $Correo = "";
                $_POST["Contraseña"] = "";
                $_POST["Ccontraseña"] = "";    
            }else{
                echo "<script>alert('Hay un error')</script>";
                
            }
        }else{
            echo "<script>alert('El correo ya existe')</script>";
        }
    }else{
        echo "<script>alert('Las constraseñas no coinciden')</script>";
    }
    
}

?>




<?php
require('config.php');;

if(isset($_SESSION["Nombre"]))
{
    header ("Location: http://http://localhost/joul24py.github.io/Principal.php");
}

if(isset($_POST["submit"])){
    $Correo = $_POST["Correo"];
    $Contrasena = $_POST["Contraseña"];
    
    $sql = "SELECT * FROM usuarios WHERE Correo='$Correo' AND Contraseña='$Contrasena'";
    $result = mysqli_query($conn, $sql);
    
    if($result -> num_rows>0)
    {
        $row = msqli_fetch_assoc($result);
        $_SESSION[Nombre] = $row['Nombre'];
        header("Location: Principal.php");
    }else{
        echo "<script>alert('La contraseña o el correo son incorrectos')</script>";
    }
     
}

?>