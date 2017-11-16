# Redes1
Projeto disciplina de redes-1 do curso Ciência da Computação-UFAL

Professor: Leandro Sales
Alunos: Hyuri Maciel e Ziran Moura

Este projeto tem como intuito o monitoramento da temperatura e luminosidade de um ambiente residêncial ou empresarial.
Também aciono dois Réles que tem intuito de acionar lâmpadas no ambiente.
Utilizamos para controle e envio dos dados dos sensores um arduino UNO integrado com um shield Ethernt. 

<h2>Descrição e funcionalidades</h2>

   <h3>Circuito e Material utilizado</h3>
   1- Arduino UNO
   
   2- Shield Ethernet W5100
   
   1- Sensor de Temperatura
   
   1- Um sensor LDR de luminosidade 
   
   2- relés de 5v de entrada
   
 <imagem do esquema>  
   
A programação do Arduino utiliza a biblioteca Ethernet que já vem embutida na IDE do Arduino. Com ela, vamos criar um Web Server que vai receber as informações pela rede e acionar as portas. Esta bicliotecas possui funções de comunicação, escrita e leitura.

O Arduino Ethernet Shield W5100 ou outro dispositivo dessa família, que além de possibilitar o acesso às informações na sua rede local, ainda pode ser conectado à internet.
   
Acoplando o Ethernet Shield W5100 ao Arduino, basta conectar o cabo de rede para que,para assim passar a monitorar o estado de sensores, chaves e outros dispositivos à partir do browser do computador. Este Shield é baseado no ethernet chip Wiznet W5100 (datasheet link) e fornece um endereço IP compatível com os protocolos TCP e UDP.   

Primeiro devemos configura o shield ethernet com um endereco IP, gateway, mascara de rede, nas váriaveis:

        mac[] = { 0xA4, 0x28, 0x72, 0xCA, 0x55, 0x2F };
        ip[] = { 192, 168, 0, 110 };
        gateway[] = { 192, 168, 0, 1 };
        subnet[] = { 255, 255, 255, 0 };
        
onde mac[] é o mac do ethernt shield.
   
EthernetServer server(port) Cria um servidor que atenda conexões de entrada na porta especificada.
Função para inicializar a parta ou servidor Web no nosso caso.

        EthernetServer server(80);
        server.begin();
        
Na função principal do arduino, Void Setup(), devemos inicalizar a configuração do ethernet shield, para que possa se comunicar com a internt.

Ethernet.begin() inicializa a biblioteca ethernet e as configurações de rede.

        Ethernet.begin(mac, ip, gateway, subnet);
Não tem nenhuma retorno.        

Com a versão 1.0, a biblioteca oferece suporte ao DHCP. Usando Ethernet.begin (mac) com a configuração de rede adequada, o escudo Ethernet obterá automaticamente um endereço IP. Isso aumenta significativamente o tamanho do esboço. Para garantir que a concessão de DHCP seja devidamente renovada quando necessário.


server.available(). Obtém um cliente que está conectado ao servidor e tem dados disponíveis para leitura. A conexão persiste quando o objeto cliente retornado fica fora do escopo; Você pode fechá-lo chamando client.stop ().

         EthernetClient client = server.available();
         
retornando um objeto Cliente; Se nenhum cliente tiver dados disponíveis para leitura, este objeto avaliará falso em uma instrução if. Exemplo:

         EthernetClient client = server.available();
        if (client) {
        server.write(client.read());
         }   
        






