
<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <title>PosteCars Registro</title>
    <link rel="stylesheet" href="estilos.css">
    <link rel="preconnect" href="https://fonts.googleapis.com">
    <link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
    <link href="https://fonts.googleapis.com/css2?family=Amatic+SC&family=Dancing+Script:wght@700&family=Roboto+Flex:opsz,wght@8..144,200&display=swap" rel="stylesheet">
</head>


<body class="body-registro">

    <form action="" method="POST" id="form">
        <div class="form">
            <h1 class="registro-letra"> Registro </h1>
            <div class="grupo">
                <input type="text" name="Nombre" id="Nombre" required><span class="barra"></span>
                <label for="">Nombre</label>

            </div>
            <div class="grupo">
                <input type="email" name="Correo" id="Correo" required><span class="barra"></span>
                <label for="">Correo institucional</label>
            </div>
            <div class="grupo">
                <input type="Password" name="Contraseña" id="Contraseña" required><span class="barra"></span>
                <label for="">Contraseña de e-siima</label>
            </div>
            <button type="submit">¡Regístrate!</button>

        </div>

    </form>

</body>

</html>
