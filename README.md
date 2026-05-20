# Contestas.io
> **Quiz Interativo via Terminal em C — Arquitetura e Fluxo do Sistema**

---

## Integrantes da Equipe
* **[Afonso Araújo]** — ahma@cesar.school
* **[André Montenegro]** — agmos@cesa.school
* **[Breno Gabriel]** — bgas@cesar.school
* **[Lucas Gabriel]** — lgcs2@cesar.school
* **[Rafael Viana]** — rlvs@cesar.school
* **[José Williams]** — jwlp@cesar.school

---

## Descrição do Tema

O **Contestas.io** é um mini quiz interativo desenvolvido na linguagem C (estilo Kahoot!) que roda diretamente no console. O principal objetivo pedagógico e técnico do projeto é a **separação estrita entre Dados (Persistência) e Lógica (Código)**.

O software inicia consumindo um banco de dados de **perguntas pré-definidas** armazenadas em um arquivo `.txt`. O motor do jogo processa essas informações dinamicamente a cada partida, o que permite que novos desafios sejam incluídos de forma assíncrona — seja editando o arquivo de texto diretamente ou através de um módulo administrativo interno —, atualizando a experiência em tempo real sem a necessidade de recompilar o código-fonte.

---

## Arquitetura e Ciclo de Execução
*O diagrama abaixo ilustra as 3 opções do menu do sistema funcionando em paralelo e suas interações com os arquivos de persistência:*

```mermaid
flowchart LR
    %% Customização de Estilos
    classDef arquivo fill:#fff5f5,stroke:#ffc9c9,stroke-width:2px;
    classDef hub fill:#e6f7ff,stroke:#bae7ff,stroke-width:2px;
    classDef fluxo fill:#f6ffed,stroke:#d9f7be,stroke-width:2px;

    %% Base de Dados Inicial
    A["perguntas.txt <br> (Perguntas Pré-definidas)"]:::arquivo

    %% Menu Central
    B["Menu Principal <br> (Loop do main.c)"]:::hub

    %% Opções do Menu Lado a Lado
    C["Opção 1: Jogar <br> (Alocação RAM + Embaralhar)"]:::fluxo
    F["Opção 2: Ver Ranking <br> (Exibe o Top 10)"]:::fluxo
    G["Opção 3: Modo Professor <br> (Insere novas questões)"]:::fluxo

    %% Arquivo de Destino do Placar
    E["ranking.txt <br> (Salvo após cada rodada)"]:::arquivo

    %% Fluxo de Entrada e Ramos do Menu
    A -->|Carrega perguntas| B
    B ---> C
    B ---> F
    B ---> G

    %% Conexões Finais de Cada Funcionalidade
    C -->|Grava placar imediato| E
    F -.->|Apenas lê dados| E
    G -->|Modo Append| A
