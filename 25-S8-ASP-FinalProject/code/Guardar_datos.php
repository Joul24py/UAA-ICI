<?php
	include('config.php');
	if(isset($_POST['susername'])){
		$Nombre=$_POST['Nombre'];
        $Correo=$_POST['Correo'];
        $Contrasena=$_POST['Contraseña'];
		$Ccontrasena=$_POST['Ccontraseña'];

		$query=$conn->query("select * from usuarios where Nombre='$Nombre'");

		if ($query->num_rows>0){
			?>
  				<span>El usuario ya existe.</span>
  			<?php 
		}

		elseif (!preg_match("/^[a-zA-Z0-9_]*$/",$Nombre)){
			?>
  				<span style="font-size:11px;">Invalid username. Space & Special Characters not allowed.</span>
  			<?php 
		}
		elseif (!preg_match("/^[a-zA-Z0-9_]*$/",$Contrasena)){
			?>
  				<span style="font-size:11px;">Invalid password. Space & Special Characters not allowed.</span>
  			<?php 
		}
		else{
			$mpassword=md5($Contrasena);
			$conn->query("insert into usuarios (Nombre,Correo,Contraseña) values ('$Nombre', '$Correo', '$Contrasena')");
			?>
  				<span>Sign up Successful.</span>
  			<?php 
		}
	}
?>






