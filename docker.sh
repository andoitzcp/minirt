sudo docker create --name temp_container my-ubuntu-c-project
sudo docker cp temp_container:/app/minirt .
sudo docker rm temp_container
