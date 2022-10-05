
        <?php include_once 'includes/templates/header.php'; ?>
        
        <?php
        require ('conexion.php');
        $nl=$_GET['id'];
           
          $query="DELETE FROM calificaciones where lista='$nl'";
            $resultado=$mysqli->query($query);
            $row=$resultado->fetch_assoc();	
        ?>
        

	    
        <?php include_once 'includes/templates/footer.php'; ?>

    