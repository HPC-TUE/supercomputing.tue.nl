<figure class="staircase">
<div class="staircase__scroll">
<svg viewBox="0 0 1000 580" role="img" aria-labelledby="staircase-title staircase-desc" xmlns="http://www.w3.org/2000/svg">
  <title id="staircase-title">HPC solutions: on the HPC staircase</title>
  <desc id="staircase-desc">A researcher asks: do I have an optimal compute job, what HPC solution options do I have, and what are my restrictions? Five ascending steps follow: 1. Personal laptop or workstation. 2. Departmental clusters (specials and silos). 3. Institutional TU/e: Umbrella and Spike-1. 4. National SURF: Snellius. 5. International EuroHPC: LUMI, Leonardo and others. Testing happens at TU/e; improving and scaling up happens at the national and European levels. Underneath all steps, the TU/e Supercomputing Center supports researchers at every step with consulting, code optimization, training, software, and access and paperwork.</desc>
  <defs>
    <marker id="staircase-arrow" viewBox="0 0 10 10" refX="8" refY="5" markerWidth="7" markerHeight="7" orient="auto-start-reverse">
      <path d="M0,0 L10,5 L0,10 z" class="st-go-fill"/>
    </marker>
    <symbol id="sc-researcher" viewBox="0 0 24 24"><path d="M13 8a4 4 0 0 1-4 4 4 4 0 0 1-4-4 4 4 0 0 1 4-4 4 4 0 0 1 4 4m4 10v2H1v-2c0-2.21 3.58-4 8-4s8 1.79 8 4m3.5-3.5V16H19v-1.5zm-2-5H17V9a3 3 0 0 1 3-3 3 3 0 0 1 3 3c0 .97-.5 1.88-1.29 2.41l-.3.19c-.57.4-.91 1.01-.91 1.7v.2H19v-.2c0-1.19.6-2.3 1.59-2.95l.29-.19c.39-.26.62-.69.62-1.16A1.5 1.5 0 0 0 20 7.5 1.5 1.5 0 0 0 18.5 9z"/></symbol>
    <symbol id="sc-laptop" viewBox="0 0 24 24"><path d="M4 6h16v10H4m16 2a2 2 0 0 0 2-2V6a2 2 0 0 0-2-2H4c-1.11 0-2 .89-2 2v10a2 2 0 0 0 2 2H0v2h24v-2z"/></symbol>
    <symbol id="sc-server" viewBox="0 0 24 24"><path d="M4 1h16a1 1 0 0 1 1 1v4a1 1 0 0 1-1 1H4a1 1 0 0 1-1-1V2a1 1 0 0 1 1-1m0 8h16a1 1 0 0 1 1 1v4a1 1 0 0 1-1 1H4a1 1 0 0 1-1-1v-4a1 1 0 0 1 1-1m0 8h16a1 1 0 0 1 1 1v4a1 1 0 0 1-1 1H4a1 1 0 0 1-1-1v-4a1 1 0 0 1 1-1M9 5h1V3H9zm0 8h1v-2H9zm0 8h1v-2H9zM5 3v2h2V3zm0 8v2h2v-2zm0 8v2h2v-2z"/></symbol>
    <symbol id="sc-umbrella" viewBox="0 0 24 24"><path d="M12 2a9 9 0 0 1 9 9h-8v8a3 3 0 0 1-3 3 3 3 0 0 1-3-3v-1h2v1a1 1 0 0 0 1 1 1 1 0 0 0 1-1v-8H3a9 9 0 0 1 9-9"/></symbol>
    <symbol id="sc-chip" viewBox="0 0 24 24"><path d="M6 4h12v1h3v2h-3v2h3v2h-3v2h3v2h-3v2h3v2h-3v1H6v-1H3v-2h3v-2H3v-2h3v-2H3V9h3V7H3V5h3zm5 11v3h1v-3zm2 0v3h1v-3zm2 0v3h1v-3z"/></symbol>
    <symbol id="sc-server-network" viewBox="0 0 24 24"><path d="M13 19h1a1 1 0 0 1 1 1h7v2h-7a1 1 0 0 1-1 1h-4a1 1 0 0 1-1-1H2v-2h7a1 1 0 0 1 1-1h1v-2H4a1 1 0 0 1-1-1v-4a1 1 0 0 1 1-1h16a1 1 0 0 1 1 1v4a1 1 0 0 1-1 1h-7zM4 3h16a1 1 0 0 1 1 1v4a1 1 0 0 1-1 1H4a1 1 0 0 1-1-1V4a1 1 0 0 1 1-1m5 4h1V5H9zm0 8h1v-2H9zM5 5v2h2V5zm0 8v2h2v-2z"/></symbol>
    <symbol id="sc-consulting" viewBox="0 0 24 24"><path d="M16.75 4.36c2.02 2.2 2.02 5.25 0 7.27l-1.68-1.69c.84-1.18.84-2.71 0-3.89zM20.06 1c3.940 4.05 3.900 10.11 0 14l-1.63-1.63c2.77-3.18 2.770-7.72 0-10.74zM9 4c2.2 0 4 1.79 4 4s-1.800 4-4 4-4-1.79-4-4 1.790-4 4-4m4 10.54c0 1.06-.29 3.53-2.2 6.29L10 16l.93-1.88C10.31 14.05 9.66 14 9 14s-1.33.05-1.95.12L8 16l-.82 4.83C5.27 18.07 5 15.6 5 14.54 2.6 15.24.994 16.5.994 18v4H17v-4c0-1.5-1.61-2.76-4-3.46"/></symbol>
    <symbol id="sc-speed" viewBox="0 0 24 24"><path d="M12 16a3 3 0 0 1-3-3c0-1.12.61-2.1 1.5-2.61l9.71-5.62-5.53 9.58c-.5.98-1.51 1.65-2.68 1.65m0-13c1.81 0 3.5.5 4.970 1.32l-2.1 1.21C14 5.19 13 5 12 5a8 8 0 0 0-8 8c0 2.21.89 4.21 2.34 5.65h.01c.39.39.39 1.02 0 1.41s-1.03.39-1.42.01A9.970 9.970 0 0 1 2 13 10 10 0 0 1 12 3m10 10c0 2.76-1.12 5.26-2.93 7.07-.39.38-1.02.38-1.41-.01a.996.996 0 0 1 0-1.41A7.950 7.950 0 0 0 20 13c0-1-.19-2-.54-2.9L20.67 8C21.5 9.5 22 11.18 22 13"/></symbol>
    <symbol id="sc-school" viewBox="0 0 24 24"><path d="M12 3 1 9l11 6 9-4.91V17h2V9M5 13.18v4L12 21l7-3.82v-4L12 17z"/></symbol>
    <symbol id="sc-package" viewBox="0 0 24 24"><path d="M21 16.5c0 .38-.21.71-.53.88l-7.9 4.44c-.16.12-.36.18-.57.18s-.41-.06-.57-.18l-7.9-4.44A.99.99 0 0 1 3 16.5v-9c0-.38.21-.71.53-.88l7.9-4.44c.16-.12.36-.18.57-.18s.41.06.57.18l7.9 4.44c.32.17.53.5.53.88zM12 4.15l-1.89 1.07L16 8.61l1.96-1.11zM6.04 7.5 12 10.850l1.96-1.1-5.88-3.4zM5 15.91l6 3.38v-6.71L5 9.21zm14 0v-6.7l-6 3.37v6.71z"/></symbol>
    <symbol id="sc-paperwork" viewBox="0 0 24 24"><path d="m23.5 17-5 5-3.5-3.5 1.5-1.5 2 2 3.5-3.5zM6 2a2 2 0 0 0-2 2v16c0 1.11.89 2 2 2h7.81c-.36-.62-.61-1.3-.73-2H6V4h7v5h5v4.08c.33-.05.67-.08 1-.08.34 0 .67.03 1 .08V8l-6-6M8 12v2h8v-2m-8 4v2h5v-2Z"/></symbol>
  </defs>
  <!-- Researcher and questions -->
  <rect x="10" y="150" width="320" height="112" rx="16" class="st-bubble"/>
  <circle cx="70" cy="280" r="7" class="st-bubble"/>
  <circle cx="76" cy="298" r="4" class="st-bubble"/>
  <text x="28" y="186" class="st-text">– Do I have an optimal compute job?</text>
  <text x="28" y="214" class="st-text">– What HPC solution options do I have?</text>
  <text x="28" y="242" class="st-text">– What are my restrictions?</text>
  <use href="#sc-researcher" x="30" y="318" width="100" height="100" class="st-ink-fill"/>
  <!-- Process annotations -->
  <text x="594" y="34" text-anchor="middle" class="st-flow">TESTING</text>
  <path d="M594,46 V186" class="st-go" marker-end="url(#staircase-arrow)"/>
  <text x="800" y="34" text-anchor="middle" class="st-flow">IMPROVING</text>
  <path d="M790,46 C780,80 764,110 758,140" class="st-go" marker-end="url(#staircase-arrow)"/>
  <path d="M852,40 C880,46 904,64 914,92" class="st-go" marker-end="url(#staircase-arrow)"/>
  <!-- Steps -->
  <rect x="190" y="360" width="160" height="60" class="st-step st-s1"/>
  <rect x="352" y="315" width="160" height="105" class="st-step st-s2"/>
  <rect x="514" y="270" width="160" height="150" class="st-step st-s3"/>
  <rect x="676" y="225" width="160" height="195" class="st-step st-s4"/>
  <rect x="838" y="180" width="160" height="240" class="st-step st-s5"/>
  <text x="270" y="383" text-anchor="middle" class="st-level">PERSONAL</text>
  <text x="270" y="404" text-anchor="middle" class="st-name">Laptop / Workstation</text>
  <text x="432" y="338" text-anchor="middle" class="st-level">DEPARTMENTAL</text>
  <text x="432" y="359" text-anchor="middle" class="st-name">Departmental Clusters</text>
  <text x="594" y="293" text-anchor="middle" class="st-level st-level--home">INSTITUTIONAL</text>
  <text x="594" y="314" text-anchor="middle" class="st-name">TU/e</text>
  <text x="756" y="248" text-anchor="middle" class="st-level st-on-dark">NATIONAL</text>
  <text x="756" y="269" text-anchor="middle" class="st-name st-on-dark">SURF</text>
  <text x="918" y="203" text-anchor="middle" class="st-level st-on-dark">INTERNATIONAL</text>
  <text x="918" y="224" text-anchor="middle" class="st-name st-on-dark">EuroHPC</text>
  <!-- Systems on each step -->
  <use href="#sc-laptop" x="248" y="312" width="44" height="44" class="st-ink-fill"/>
  <text x="432" y="252" text-anchor="middle" class="st-label">Specials / Silos</text>
  <use href="#sc-server" x="392" y="265" width="38" height="38" class="st-ink-fill"/>
  <use href="#sc-server" x="434" y="265" width="38" height="38" class="st-ink-fill"/>
  <text x="594" y="207" text-anchor="middle" class="st-label">Umbrella · Spike-1</text>
  <a href="documentation/" class="st-link"><title>Umbrella HPC Cluster</title><use href="#sc-umbrella" x="550" y="218" width="42" height="42" class="st-accent-fill"/></a>
  <a href="spike-1/" class="st-link"><title>Spike-1</title><use href="#sc-chip" x="598" y="218" width="42" height="42" class="st-accent-fill"/></a>
  <a href="https://www.surf.nl/en/services/snellius-the-national-supercomputer" target="_blank" class="st-link">
    <title>Snellius at SURF</title>
    <text x="756" y="160" text-anchor="middle" class="st-label">Snellius</text>
    <use href="#sc-server-network" x="733" y="170" width="46" height="46" class="st-ink-fill"/>
  </a>
  <a href="https://eurohpc-ju.europa.eu/" target="_blank" class="st-link">
    <title>EuroHPC supercomputers</title>
    <text x="918" y="114" text-anchor="middle" class="st-label">LUMI · Leonardo · …</text>
    <use href="#sc-server" x="858" y="124" width="40" height="46" class="st-ink-fill"/>
    <use href="#sc-server" x="898" y="124" width="40" height="46" class="st-ink-fill"/>
    <use href="#sc-server" x="938" y="124" width="40" height="46" class="st-ink-fill"/>
  </a>
  <!-- Floor -->
  <path d="M10,420 H998" class="st-floor"/>
  <!-- The Supercomputing Center: the multi-tool under every step -->
  <rect x="10" y="438" width="988" height="86" rx="43" class="st-tool"/>
  <path d="M53,438 H250 V524 H53 A43,43 0 0 1 53,438 Z" class="st-tool-cap"/>
  <circle cx="36" cy="481" r="5" class="st-rivet"/>
  <circle cx="984" cy="481" r="4" class="st-rivet st-rivet--dark"/>
  <text x="58" y="474" class="st-tool-title">TU/e Supercomputing</text>
  <text x="58" y="494" class="st-tool-title">Center</text>
  <text x="58" y="512" class="st-tool-sub">With you at every step</text>
  <g class="st-tool-items">
    <use href="#sc-consulting" x="270" y="461" width="22" height="22"/>
    <text x="300" y="477">Consulting</text>
    <path d="M407,456 V506" class="st-tool-sep"/>
    <use href="#sc-speed" x="420" y="461" width="22" height="22"/>
    <text x="450" y="477">Code optimization</text>
    <path d="M590,456 V506" class="st-tool-sep"/>
    <use href="#sc-school" x="603" y="461" width="22" height="22"/>
    <text x="633" y="477">Training</text>
    <path d="M718,456 V506" class="st-tool-sep"/>
    <use href="#sc-package" x="731" y="461" width="22" height="22"/>
    <text x="761" y="477">Software</text>
    <path d="M844,456 V506" class="st-tool-sep"/>
    <use href="#sc-paperwork" x="857" y="461" width="22" height="22"/>
    <text x="887" y="470">Access &amp;</text>
    <text x="887" y="487">paperwork</text>
  </g>
  <!-- Title -->
  <text x="998" y="566" text-anchor="end" class="st-title">HPC solutions: on the HPC “staircase”</text>
</svg>
</div>
</figure>
