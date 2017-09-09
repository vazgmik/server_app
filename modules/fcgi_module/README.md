# fcgi_module
fcgi module for processing http requests via nginx

Simple implementation config for NGINX:

server { 
	server_name localhost; 

	location / { 
		fastcgi_pass 127.0.0.1:9000; 
		#fastcgi_pass  unix:/tmp/fastcgi/mysocket; 
		#fastcgi_pass localhost:9000; 
		 
		include fastcgi_params; 
	} 
}
