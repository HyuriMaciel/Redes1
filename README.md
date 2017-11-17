# Redes1
Projeto disciplina de redes-1 do curso Ciência da Computação-UFAL

Professor: Leandro Sales
Alunos: Hyuri Maciel e Ziran Moura


<h2>Descrição e funcionalidades</h2>

Este projeto tem como intuito realizar o monitoramento da temperatura, umidade  e luminosidade de um ambiente residêncial ou empresarial. Para a realização do projeto foram usados conceitos de socket() e read() em liguagem C adaptada para programação em arduino.

O arduino Uno capitura dados externos do ambiente através dos sensores trata esses dados através de bibliotecas especificas. esses dados podem ser acessados externamente através de um browse. Basta realizar a cominucação com o IP válido que foi conficurado no arduino.


Utilizamos para controle e envio dos dados dos sensores um arduino UNO integrado a um shield Ethernt. 

<h3>Circuito e Material utilizado</h3>
   
   1- Arduino UNO
   
   2- Shield Ethernet W5100   
     
   1- Um sensor LDR de luminosidade 
   
   1- sensor STH15 (sensor de temperatura e umidade)
   

   
A programação do Arduino utiliza a biblioteca Ethernet.h que já vem embutida na IDE do Arduino.

Essas biblioteca é projetada para trabalhar com o Arduino Ethernet Shield (Ethernet.h). A biblioteca permite que uma placa Arduino se conecte à internet. O podendo servir como um servidor que aceita conexões de recebimento ou um cliente que faz a saída de dados. As bibliotecas suportam até quatro conexões simultâneas (entrada ou saída ou uma combinação).

A biblioteca Ethernet (Ethernet.h) gerencia o chip W5100. 

Arduino comunica com o Shield usando o SPI. Que está nos pinos digitais 11, 12 e 13 no Uno.

Essa biblioteca suporta o shield  Arduino Ethernet Shield W5100 ou outro dispositivo dessa família.
   
Acoplando o Ethernet Shield W5100 ao Arduino, basta conectar o cabo de rede para que,para assim passar a monitorar o estado de sensores, chaves e outros dispositivos à partir do browser do computador. Este Shield é baseado no ethernet chip Wiznet W5100 (datasheet link) e fornece um endereço IP compatível com os protocolos TCP e UDP.   

Primeiro devemos configura o shield ethernet com um endereco IP, gateway, mascara de rede, nas váriaveis, Exemplo:

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
         
<h3>Dificuldades e Trabalhos futuros</h3>
 
Uma dificuldade foi para criar um servidor Web onde poderiamos hospedar uma página web mais interativa, ficando assim para trabalhos futuros.

O que poderíamos ter incrementado a mais do projeto seria mais sensores, como de movimento, umidade, chamas etc, com isso teríamos um maior monitoramento do ambiente.
Também poderíamos de incluído o controle do ar condicionado, fazendo uma comparação da informação da temperatura fornecida pelo sensor de temperatura e fazendo uma inferência sobre esses dados. Não só inferir sobre os dados de temperatura mais utilizar todos os dados fornecidos pelos sensores para inferir comportamentos na sala, como ligar e desligar uma lâmpada, abrir e fechar uma cortina.
         
         
         
        






