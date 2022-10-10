<?php 
	include('config.php');
	session_start();
	if(isset($_POST['Nombre'])){
		$Nombre=$_POST['Nombre'];
        $Correo=$_POST['Correo'];
		$Contrasena=md5($_POST['Contraseña']);

		$query=$conn->query("select * from usuarios where Nombre='$Nombre' and Correo='$Correo' and Contraseña='$Contrasena'");

		if ($query->num_rows>0){
			$row=$query->fetch_array();
			$_SESSION['usuario']=$row['id']; 
		}
		else{
			?>
  				<span>Login Failed. User not Found.</span>
  			<?php 
		}
	}
?>