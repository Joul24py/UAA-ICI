  <!DOCTYPE html>
  <html>
    <head>
        <meta charset="utf-8">
        <title>UAAGRADES</title>
        <script>		
            function soloNumeros(e)
            {
            var key = window.Event ? e.which : e.keyCode
            return ((key >= 48 && key <= 57) || (key==8))
            }
        </script>
	</head>
   
    <body>
        <?php include_once 'includes/templates/header.php'; ?>

            <article class="entrada-blog back2">
                <div class="imagen">
                    <img src="img2/blog1.jpg" alt="Entrada de blog">
                </div>
                <div class="texto-entrada color-texto">
                    <a href="entrada.html">
                        <h4>Univeridad Autónoma de Aguascalientes</h4>
                    </a>
                    <p>Escrito el: <span> 24/04/2020 </span> por: <span> Admin </span> </p>
                    <p>Ésta página fue creada por alumnos de la universidad atónoma de aguascalientes de la carrea de ingeniería en computación inteligente (ICI) de cuarto semestre.</p>
                </div>
            </article>
            <div class="back1">
                <section class="contenedor seccion color-texto">
                    <h2 class="fw-300 centrar-texto altura">Más sobre la página</h2>

                    <div class="iconos-nosotros">
                        <div class="icono">
                            <img src="img2/help.png" alt="Icono Seguridad">
                            <h3>¿Qué es?</h3>
                            <p> Lorem ipsum dolor sit amet, consectetur adipisicing elit. A accusamus quae corrupti dolorem nemo consectetur expedita ab alias, voluptates asperiores ut vel at excepturi blanditiis repellendus rem aspernatur, possimus illo.</p>

                        </div>

                        <div class="icono">
                            <img src="img2/clock.png" alt="Icono Mejor Precio">
                            <h3>Tiempo</h3>
                            <p>Quasi quibusdam, quos deserunt, recusandae iusto dolorem voluptatibus quaerat veritatis consectetur culpa sit dignissimos maiores iure id, magnam non voluptatum molestiae doloremque.</p>

                        </div>

                        <div class="icono">
                            <img src="img2/verified.png" alt="Icono a Tiempo">
                            <h3>Facilidad de uso</h3>
                            <p>Quasi quibusdam, quos deserunt, recusandae iusto dolorem voluptatibus quaerat veritatis consectetur culpa sit dignissimos maiores iure id, magnam non voluptatum molestiae doloremque.</p>

                        </div>

                    </div>
                    <div class="centrar-texto color-texto">
                        <nav id="navegacion" class="navegacion">
                            <div>Icons made by <a href="https://www.flaticon.com/authors/freepik" title="Freepik">Freepik</a> from <a href="https://www.flaticon.com/" title="Flaticon">www.flaticon.com</a></div>
                        </nav>
                    </div>

                    <div>
                    <a href="calificaciones.php" class="btn btn-primario">Lista de calificaciones</a>
                    <a href="asistencia.php" class="btn btn-primario">Lista de asistencia</a>

                    </div>
                </section>

            </div>
        <?php include_once 'includes/templates/footer.php'; ?>
    </body>
</html>