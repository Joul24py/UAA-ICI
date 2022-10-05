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
                <div class="texto-entrada color-texto2">
                    <a href="entrada.html">
                        <h4>Univesidad Autónoma de Aguascalientes</h4>
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
                            <img src="img2/help.png" alt="Icono quienes somos">
                            <h3>¿Qué es?</h3>
                            <p> Esta es una página que ayuda a profesores a tener la mejor organización para listas de calificaciones de sus alumnos,ya que cuenta con las pondraciones en sus diferentes rasgos y les facilita obtener automáticamente el promedio, quiénes han reprobado por faltas o por no cumplir el mínimo promedio. </p>

                        </div>

                        <div class="icono">
                            <img src="img2/clock.png" alt="Icono tiempo">
                            <h3>Tiempo</h3>
                            <p>Ahorra mucho tiempo. ¿Para quién no es tedioso sacar promedios? con esta página los obtendras en muy poco tiempo y sin errores.</p>

                        </div>

                        <div class="icono">
                            <img src="img2/verified.png" alt="Icono facilidad">
                            <h3>Facilidad de uso</h3>
                            <p>Es tan sencillo de usar, que obtendrás las calificaciones en menos de un segundo. Lo único que tienes que hacer es introducir los nombres de tus alumnos y sus calificaciones tal cual salen de tu lista.</p>

                        </div>

                    </div>
                    <div class="centrar-texto color-texto">
                        <nav id="navegacion" class="navegacion">
                            <div>Icons made by <a href="https://www.flaticon.com/authors/freepik" title="Freepik">Freepik</a> from <a href="https://www.flaticon.com/" title="Flaticon">www.flaticon.com</a></div>
                        </nav>
                    </div>

                    <div>
                    <a href="calificaciones2.php" class="btn btn-primario">Lista de calificaciones</a>
                    

                    </div>
                </section>

            </div>
        <?php include_once 'includes/templates/footer.php'; ?>
    </body>
</html>