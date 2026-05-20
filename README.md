#  Contestas.io
> **Quiz Interativo via Terminal em C — Arquitetura e Fluxo do Sistema**

---

##  1. O Conceito Pedagógico

O principal objetivo do projeto é a **separação estrita entre Dados (Persistência) e Lógica (Código)**.
* O jogo inicia consumindo um banco de dados de **perguntas pré-definidas** armazenadas em um arquivo `.txt`.
* O motor em C processa essas informações dinamicamente a cada partida.
* O sistema permite evolução contínua através do cadastro opcional de novas perguntas e da atualização instantânea do ranking de jogadores.

---

##  2. Arquitetura e Ciclo de Execução
*(Utilize este diagrama para mostrar à banca as 3 opções do menu funcionando em paralelo)*

```mermaid
flowchart LR
    %% Customização de Estilos
    classDef arquivo fill:#fff5f5,stroke:#ffc9c9,stroke-width:2px;
    classDef hub fill:#e6f7ff,stroke:#bae7ff,stroke-width:2px;
    classDef fluxo fill:#f6ffed,stroke:#d9f7be,stroke-width:2px;

    %% Base de Dados Inicial
    A[" perguntas.txt <br> (Perguntas Pré-definidas)"]:::arquivo

    %% Menu Central
    B[" Menu Principal <br> (Loop do main.c)"]:::hub

    %% Opções do Menu Lado a Lado
    C[" Opção 1: Jogar <br> (Alocação RAM + Embaralhar)"]:::fluxo
    F[" Opção 2: Ver Ranking <br> (Exibe o Top 10)"]:::fluxo
    G[" Opção 3: Modo Professor <br> (Insere novas questões)"]:::fluxo

    %% Arquivo de Destino do Placar
    E[" ranking.txt <br> (Salvo após cada rodada)"]:::arquivo

    %% Fluxo de Entrada e Ramos do Menu
    A -->|Carrega perguntas| B
    B ---> C
    B ---> F
    B ---> G

    %% Conexões Finais de Cada Funcionalidade
    C -->|Grava placar imediato| E
    F -.->|Apenas lê dados| E
    G -->|Modo Append| A
