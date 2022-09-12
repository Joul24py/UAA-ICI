//Crear un login donde usuario y contraseña sean hola
//Esto es dentro del metodo private void button1_Click(object sender, EventArgs e)
int verif = 0;
            if(usuario.Text != "Hola" && contrasena.Text != "Hola")
            {
                MessageBox.Show("Usuario y Contraseña Incorrectos");
                verif = 1;
            }
            else
            {
                if (usuario.Text != "Hola")
                {
                    MessageBox.Show("Usuario Incorrecto");
                    verif = 1;
                }
                if (contrasena.Text != "Hola")
                {
                    MessageBox.Show("Contraseña Incorrecta");
                    verif = 1;
                }
                if (verif == 0)
                {
                    MessageBox.Show("Éxito al ingresar");
                }
            }